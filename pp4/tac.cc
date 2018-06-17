/* File: tac.cc
 * ------------
 * Implementation of Location class and Instruction class/subclasses.
 */
  
#include "tac.h"
#include "mips.h"
#include <string.h>

Location::Location(Segment s, int o, const char *name) :
  variableName(strdup(name)), segment(s), offset(o){}

 
void Instruction::Print() {
  printf("\t%s ;\n", printed);
}

void Instruction::Emit(Mips *mips) {
  if (*printed)
    mips->Emit("# %s", printed);   // emit TAC as comment into assembly
  EmitSpecific(mips);
} 

LoadConstant::LoadConstant(Location *d, int v)
  : dst(d), val(v) {
  Assert(dst != NULL);
  sprintf(printed, "%s = %d", dst->GetName(), val);
}
void LoadConstant::EmitSpecific(Mips *mips) {
  mips->EmitLoadConstant(dst, val);
}


LoadStringConstant::LoadStringConstant(Location *d, const char *s)
  : dst(d) {
  Assert(dst != NULL && s != NULL);
  const char *quote = (*s == '"') ? "" : "\"";
  str = new char[strlen(s) + 2*strlen(quote) + 1];
  sprintf(str, "%s%s%s", quote, s, quote);
  quote = (strlen(str) > 50) ? "...\"" : "";
  sprintf(printed, "%s = %.50s%s", dst->GetName(), str, quote);
}
void LoadStringConstant::EmitSpecific(Mips *mips) {
  mips->EmitLoadStringConstant(dst, str);
}
     

LoadLabel::LoadLabel(Location *d, const char *l)
  : dst(d), label(strdup(l)) {
  Assert(dst != NULL && label != NULL);
  sprintf(printed, "%s = %s", dst->GetName(), label);
}
void LoadLabel::EmitSpecific(Mips *mips) {
  mips->EmitLoadLabel(dst, label);
}


Assign::Assign(Location *d, Location *s)
  : dst(d), src(s) {
  Assert(dst != NULL && src != NULL);
  sprintf(printed, "%s = %s", dst->GetName(), src->GetName());
}
void Assign::EmitSpecific(Mips *mips) {
  mips->EmitCopy(dst, src);
}


Load::Load(Location *d, Location *s, int off)
  : dst(d), src(s), offset(off) {
  Assert(dst != NULL && src != NULL);
  if (offset) 
    sprintf(printed, "%s = *(%s + %d)", dst->GetName(), src->GetName(), offset);
  else
    sprintf(printed, "%s = *(%s)", dst->GetName(), src->GetName());
}
void Load::EmitSpecific(Mips *mips) {
  mips->EmitLoad(dst, src, offset);
}

Store::Store(Location *d, Location *s, int off)
  : dst(d), src(s), offset(off) {
  Assert(dst != NULL && src != NULL);
  if (offset)
    sprintf(printed, "*(%s + %d) = %s", dst->GetName(), offset, src->GetName());
  else
    sprintf(printed, "*(%s) = %s", dst->GetName(), src->GetName());
}
void Store::EmitSpecific(Mips *mips) {
  mips->EmitStore(dst, src, offset);
}
 
const char * const BinaryOp::opName[BinaryOp::NumOps] = {"+", "-", "*", "/", "%", "==", "<", "&&", "||"};

BinaryOp::OpCode BinaryOp::OpCodeForName(const char *name) {
  for (int i = 0; i < NumOps; i++) 
    if (opName[i] && !strcmp(opName[i], name))
	return (OpCode)i;
  Failure("Unrecognized Tac operator: '%s'\n", name);
  return Add; // can't get here, but compiler doesn't know that
}

BinaryOp::BinaryOp(OpCode c, Location *d, Location *o1, Location *o2)
  : code(c), dst(d), op1(o1), op2(o2) {
  Assert(dst != NULL && op1 != NULL && op2 != NULL);
  Assert(code >= 0 && code < NumOps);
  sprintf(printed, "%s = %s %s %s", dst->GetName(), op1->GetName(), opName[code], op2->GetName());
}
void BinaryOp::EmitSpecific(Mips *mips) {	  
  mips->EmitBinaryOp(code, dst, op1, op2);
}


Label::Label(const char *l) : label(strdup(l)) {
  Assert(label != NULL);
  *printed = '\0';
}
void Label::Print() {
  printf("%s:\n", label);
}
void Label::EmitSpecific(Mips *mips) {
  mips->EmitLabel(label);
}

 
Goto::Goto(const char *l) : label(strdup(l)) {
  Assert(label != NULL);
  sprintf(printed, "Goto %s", label);
}
void Goto::EmitSpecific(Mips *mips) {	  
  mips->EmitGoto(label);
}

IfZ::IfZ(Location *te, const char *l)
   : test(te), label(strdup(l)) {
  Assert(test != NULL && label != NULL);
  sprintf(printed, "IfZ %s Goto %s", test->GetName(), label);
}
void IfZ::EmitSpecific(Mips *mips) {	  
  mips->EmitIfZ(test, label);
}


BeginFunc::BeginFunc() {
  sprintf(printed,"BeginFunc (unassigned)");
  frameSize = -555; // used as sentinel to recognized unassigned value
}
void BeginFunc::SetFrameSize(int numBytesForAllLocalsAndTemps) {
  frameSize = numBytesForAllLocalsAndTemps; 
  sprintf(printed,"BeginFunc %d", frameSize);
}
void BeginFunc::EmitSpecific(Mips *mips) {
  mips->EmitBeginFunction(frameSize);
}

EndFunc::EndFunc() : Instruction() {
  sprintf(printed, "EndFunc");
}
void EndFunc::EmitSpecific(Mips *mips) {
  mips->EmitEndFunction();
}

 
Return::Return(Location *v) : val(v) {
  sprintf(printed, "Return %s", val? val->GetName() : "");
}
void Return::EmitSpecific(Mips *mips) {	  
  mips->EmitReturn(val);
}


PushParam::PushParam(Location *p)
  :  param(p) {
  Assert(param != NULL);
  sprintf(printed, "PushParam %s", param->GetName());
}
void PushParam::EmitSpecific(Mips *mips) {
  mips->EmitParam(param);
} 

PopParams::PopParams(int nb)
  :  numBytes(nb) {
  sprintf(printed, "PopParams %d", numBytes);
}
void PopParams::EmitSpecific(Mips *mips) {
  mips->EmitPopParams(numBytes);
} 



LCall::LCall(const char *l, Location *d)
  :  label(strdup(l)), dst(d) {
  sprintf(printed, "%s%sLCall %s", dst? dst->GetName(): "", dst?" = ":"", label);
}
void LCall::EmitSpecific(Mips *mips) {
  mips->EmitLCall(dst, label);
}

ACall::ACall(Location *ma, Location *d)
  : dst(d), methodAddr(ma) {
  Assert(methodAddr != NULL);
  sprintf(printed, "%s%sACall %s", dst? dst->GetName(): "", dst?" = ":"",
	    methodAddr->GetName());
}
void ACall::EmitSpecific(Mips *mips) {
  mips->EmitACall(dst, methodAddr);
} 


VTable::VTable(const char *l, List<const char *> *m)
  : methodLabels(m), label(strdup(l)) {
  Assert(methodLabels != NULL && label != NULL);
  sprintf(printed, "VTable for class %s", l);
}

void VTable::Print() {
  printf("VTable %s =\n", label);
  for (int i = 0; i < methodLabels->NumElements(); i++) 
    printf("\t%s,\n", methodLabels->Nth(i));
  printf("; \n"); 
}
void VTable::EmitSpecific(Mips *mips) {
  mips->EmitVTable(label, methodLabels);
}

_PrintInt::_PrintInt() {
  sprintf(printed, "PrintInt (BuiltIn)");
}
void _PrintInt::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_PrintInt");
  // mips->Emit("subu $sp, $sp, 8\t# decrement sp to make space to save v0, a0");
  // mips->Emit("sw $v0, 8($sp)\t# save v0");
  // mips->Emit("sw $a0, 4($sp)\t# save a0");
  mips->Emit("li $v0, 1\t\t# set syscall code");
  mips->Emit("lw $a0, 4($sp)\t# load argument");
  mips->Emit("syscall\t\t# execute syscall");
  // mips->Emit("lw $a0, 4($sp)\t# restore a0");
  // mips->Emit("lw $v0, 8($sp)\t# restore v0");
  // mips->Emit("addu $sp, $sp, 8\t# pop params off stack");
  mips->Emit("jr $ra\t\t# return from function");
}

_PrintString::_PrintString() {
  sprintf(printed, "PrintString (BuiltIn)");
}
void _PrintString::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_PrintString");
  // mips->Emit("subu $sp, $sp, 8\t# decrement sp to make space to save v0, a0");
  // mips->Emit("sw $v0, 8($sp)\t# save v0");
  // mips->Emit("sw $a0, 4($sp)\t# save a0");
  mips->Emit("li $v0, 4\t\t# set syscall code");
  mips->Emit("lw $a0, 4($sp)\t# load argument");
  mips->Emit("syscall\t\t# execute syscall");
  // mips->Emit("lw $a0, 4($sp)\t# restore a0");
  // mips->Emit("lw $v0, 8($sp)\t# restore v0");
  // mips->Emit("addu $sp, $sp, 8\t# pop params off stack");
  mips->Emit("jr $ra\t\t# return from function");
}

_PrintBool::_PrintBool() {
  sprintf(printed, "PrintBool (BuiltIn)");
}
void _PrintBool::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_PrintBool");
  mips->Emit(".data\t\t\t# create string constant marked with label");
  mips->Emit("_string_true: .asciiz \"true\"");
  mips->Emit("_string_false: .asciiz \"false\"");
  mips->Emit(".text");
  // mips->Emit("subu $sp, $sp, 8\t# decrement sp to make space to save v0, a0");
  // mips->Emit("sw $v0, 8($sp)\t# save v0");
  // mips->Emit("sw $a0, 4($sp)\t# save a0");
  mips->Emit("li $v0, 4\t\t# set syscall code");
  mips->Emit("beqz $t0, _false\t# test bool value");
  mips->Emit("la $a0, _string_true\t# print true");
  mips->Emit("b _PrintBoolStr\t# go on to call syscall");
  mips->EmitLabel("_false");
  mips->Emit("la $a0, _string_false\t# print false");
  mips->EmitLabel("_PrintBoolStr");
  mips->Emit("syscall\t\t# execute syscall");
  // mips->Emit("lw $a0, 4($sp)\t# restore a0");
  // mips->Emit("lw $v0, 8($sp)\t# restore v0");
  // mips->Emit("addu $sp, $sp, 8\t# pop params off stack");
  mips->Emit("jr $ra\t\t# return from function");
}

_Halt::_Halt() {
  sprintf(printed, "Halt (BuiltIn)");  
}
void _Halt::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_Halt");

  mips->Emit("jr $ra\t\t# return from function");
}

_Alloc::_Alloc() {
  sprintf(printed, "Alloc (BuiltIn)");
}
void _Alloc::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_Alloc");

  mips->Emit("jr $ra\t\t# return from function");
}

_ReadLine::_ReadLine() {
  sprintf(printed, "ReadLine (BuiltIn)");
}
void _ReadLine::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_ReadLine"); 
  mips->Emit(".data\t\t\t# create buffer marked with label");
  mips->Emit("buffer: .space 80");
  mips->Emit(".text");
  mips->Emit("li $v0, 8\t\t# set syscall code");
  mips->Emit("la $a0, buffer\t# load byte space into address");
  mips->Emit("li $a1, 80\t# allot the byte space for string");
  mips->Emit("syscall\t\t# execute syscall");
  mips->Emit("move $v0, $a0\t# return address to buffer");
  mips->Emit("jr $ra\t\t# return from function");
}

_ReadInteger::_ReadInteger() {
  sprintf(printed, "ReadInteger (BuiltIn)");
}
void _ReadInteger::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_ReadInteger");
  // mips->Emit("subu $sp, $sp, 4\t# decrement sp to make space to save v0, a0");
  // mips->Emit("sw $v0, 4($sp)\t# save v0");
  mips->Emit("li $v0, 5\t\t# set syscall code");
  mips->Emit("syscall\t\t# execute syscall");
  // mips->Emit("sw $v0, -8($fp)\t# write integer read to memory");
  // mips->Emit("lw $v0, 4($sp)\t# restore v0");
  // mips->Emit("addu $sp, $sp, 4\t# pop params off stack");
  mips->Emit("jr $ra\t\t# return from function");
}

_StringEqual::_StringEqual() {
  sprintf(printed, "StringEqual (BuiltIn)");  
}
void _StringEqual::EmitSpecific(Mips* mips) {
  mips->EmitLabel("_StringEqual");

  mips->Emit("jr $ra\t\t# return from function");
}

