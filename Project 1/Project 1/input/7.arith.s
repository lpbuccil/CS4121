<Type> -> <INTEGER>
<VarDecl> -> <IDENTIFIER>
<IdentifierList> -> <VarDecl>
<VarDecl> -> <IDENTIFIER>
<IdentifierList> -> <IdentifierList> <CM> <VarDecl>
<VarDecl> -> <IDENTIFIER>
<IdentifierList> -> <IdentifierList> <CM> <VarDecl>
<VarDecl> -> <IDENTIFIER>
<IdentifierList> -> <IdentifierList> <CM> <VarDecl>
<VarDecl> -> <IDENTIFIER>
<IdentifierList> -> <IdentifierList> <CM> <VarDecl>
<DeclList> -> <Type> <IdentifierList> <SC>
<Type> -> <INTEGER>
<FunctionDecl> ->  <Type> <IDENTIFIER> <LP> <RP> <LBR>
<ProcedureHead> -> <FunctionDecl>
<Variable> -> <IDENTIFIER>
<Constant> -> <INTCON>
<Factor> -> <Constant>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>
Assigning 0 = 1
<Statement> -> <Assignment>
<StatementList> -> <Statement>
<Variable> -> <IDENTIFIER>
<Constant> -> <INTCON>
<Factor> -> <Constant>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>
Assigning 1 = 2
<Statement> -> <Assignment>
<StatementList> -> <StatementList> <Statement>
<Variable> -> <IDENTIFIER>
<Constant> -> <INTCON>
<Factor> -> <Constant>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>
Assigning 2 = 3
<Statement> -> <Assignment>
<StatementList> -> <StatementList> <Statement>
<Variable> -> <IDENTIFIER>
<Constant> -> <INTCON>
<Factor> -> <Constant>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<Assignment> -> <Variable> <ASSIGN> <Expr> <SC>
Assigning 3 = 4
<Statement> -> <Assignment>
<StatementList> -> <StatementList> <Statement>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <AddExpr> <PLUS> <MulExpr> 
1 + 2
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <MulExpr> <TIMES> <Factor> 
<AddExpr> -> <AddExpr> <PLUS> <MulExpr> 
3 + 12
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>
15
<Statement> -> <IOStatement>
<StatementList> -> <StatementList> <Statement>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <MulExpr>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <AddExpr> <MINUS> <MulExpr> 
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<Factor> -> <LP> <Expr> <RP>
<MulExpr> -> <Factor>
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <MulExpr> <DIVIDE> <Factor> 
<AddExpr> -> <AddExpr> <PLUS> <MulExpr> 
1 + 1
<Variable> -> <IDENTIFIER>
<Factor> -> <Variable>
<MulExpr> -> <Factor>
<AddExpr> -> <AddExpr> <PLUS> <MulExpr> 
2 + 2
<SimpleExpr> -> <AddExpr>
<Expr> -> <SimpleExpr>
<IOStatement> -> <WRITE> <LP> <Expr> <RP> <SC>
4
<Statement> -> <IOStatement>
<StatementList> -> <StatementList> <Statement>
<ProcedureBody> -> <StatementList> <RBR>
<ProcedureDecl> -> <ProcedureHead> <ProcedureBody>
<Procedures> -> epsilon
<Procedures> -> <ProcedureDecl> <Procedures>
<Program> -> <DeclList> <Procedures>
