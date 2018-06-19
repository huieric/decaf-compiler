/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp4: You will need to extend the Decl classes to implement 
 * code generation for declarations.
 */

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"
#include "ast_type.h"

class Type;
class NamedType;
class Identifier;
class Stmt;
class Scope;
class Location;
class CodeGenerator;

class Decl : public Node 
{
  protected:
    Identifier *id;
    Scope* scope;
  
  public:
    Decl(Identifier *name);
    friend ostream& operator<<(ostream& out, Decl *d) { return out << d->id; }

    const char* GetName() { return id->GetName(); }
    Scope* GetScope() { return scope; }
    virtual int GetMemBytes() = 0;

    virtual bool IsEquivalentTo(Decl* other) { return true; }

    virtual Location* Emit(CodeGenerator* cg) = 0;
    virtual void BuildScope(Scope* parent);
};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    Location* memLoc;    
    
  public:
    VarDecl(Identifier *name, Type *type);

    bool IsEquivalentTo(Decl* other);    
    Type* GetType() { return type; }
    int GetMemBytes();
    void SetMemLoc(Location* l) { memLoc = l; }
    Location* GetMemLoc() { return memLoc; }

    Location* Emit(CodeGenerator* cg);
};

class ClassDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;

  public:
    ClassDecl(Identifier *name, NamedType *extends, 
              List<NamedType*> *implements, List<Decl*> *members);

    Type* GetType() { return new NamedType(id); }
    List<Decl*>* GetMembers() { return members; }
    NamedType* GetExtends() { return extends; }
    List<NamedType*>* GetImplements() { return implements; }
    int GetMemBytes();    

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
};

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);

    Type* GetType() { return new NamedType(id); }
    List<Decl*>* GetMembers() { return members; }
    int GetMemBytes() { return 0; }

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    std::string* label;
    int localOffset;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);

    Type* GetType() { return returnType; }
    bool IsEquivalentTo(Decl* other);
    List<VarDecl*>* GetFormals() { return formals; }
    Type* GetReturnType() { return returnType; }
    int GetMemBytes() { return 0; }
    const char* GetLabel();
    int GetLocalOffset() { return localOffset; }
    void SetLocalOffset(int offset) { localOffset = offset; }

    Location* Emit(CodeGenerator* cg);
    void BuildScope(Scope* parent);
};

#endif
