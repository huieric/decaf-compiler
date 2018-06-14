/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp3: You will need to extend the Decl classes to implement 
 * semantic processing including detection of declaration conflicts 
 * and managing scoping issues.
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

    virtual bool IsEquivalentTo(Decl* other) { return true; }

    virtual void BuildScope(Scope* parent);
    virtual void Check() = 0;
};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl(Identifier *name, Type *type);

    bool IsEquivalentTo(Decl* other);
    
    Type* GetType() { return type; }
    void Check();

  private:
    void CheckType();
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

    void BuildScope(Scope* parent);
    void Check();    

  private:
    void CheckExtends(); // check the class extended
    void CheckImplements(); // check implements

    void CheckExtendedMembers(NamedType* extends); // check if override legal
    void CheckImplementedMembers(NamedType* implements); // check if implements leagal
    void CheckImplementedInterfaces(NamedType* interface);
    void CheckAgainstScope(Scope* scope);
};

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);

    Type* GetType() { return new NamedType(id); }
    List<Decl*>* GetMembers() { return members; }
    void BuildScope(Scope* parent);
    void Check();
};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);

    Type* GetType() { return returnType; }
    bool IsEquivalentTo(Decl* other);
    List<VarDecl*>* GetFormals() { return formals; }
    Type* GetReturnType() { return returnType; }

    void BuildScope(Scope* parent);
    void Check();  
};

#endif
