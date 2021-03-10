
#include "tree.h"

tree makeNode0(char *x){
    tree root;
    root = (tree) malloc(sizeof(struct node));
    root->label = x;
    root->leftmostchild = NULL;
    root->rightsibling = NULL;
    return root;
}

tree makeNode1(char *x, tree t){
    tree rt;
    rt = (tree) malloc(sizeof(struct node));
    rt = makeNode0(x);
    rt->leftmostchild = t;
    return rt;
}
tree makeNode3(char *x, tree t1, tree t2, tree t3){
    tree rt;
    rt = makeNode1(x, t1);
    t1->rightsibling = t2;
    t2->rightsibling = t3;
    return rt;
}

tree makeNode4(char *x, tree t1, tree t2, tree t3, tree t4){
    tree rt;
    rt = makeNode1(x, t1);
    t1->rightsibling = t2;
    t2->rightsibling = t3;
    t3->rightsibling = t4;
    return rt;
}

void traverse(tree root){
    tree temp = root;
    
    printf("%s\t\n", temp->label);
    if(temp->leftmostchild != NULL){
        printf("\t");
        traverse(temp->leftmostchild);
    }

    while(temp->rightsibling != NULL){
        // printf("\t");
        traverse(temp->rightsibling);
        temp = temp->rightsibling;
    }
}



char *nextterminal;

tree E(){
    tree c;
    tree et;
    c = C();
    if(c != failed){
        et = ET();
        if(et != failed){
            tree rt;
            rt = makeNode1("E", c);
            c->rightsibling = et;
            return rt;
        }else{return failed;}
    }else{return failed;}
}

tree ET(){
    if(*nextterminal == '|'){
        tree rt;
        tree e;
        nextterminal++;
        e = E();
        if(e != failed){
            // nextterminal++;
            rt = makeNode1("ET", makeNode0("|"));
            rt->leftmostchild->rightsibling = e;
            return rt;
        }else{return failed;}
    }else{  return  makeNode1("ET", makeNode0("e"));  }
}

tree C(){
    tree s;
    tree ct;
    s = S();
    if(s != failed){
        ct = CT();
        if(ct != failed){
            tree rt;
            rt = makeNode1("C", s);
            s->rightsibling = ct;
            return rt;
        }else{return failed;}
    }else{return failed;}
}

tree CT(){
    if(*nextterminal == '.'){
        tree rt;
        tree c;
        nextterminal++;
        c = C();
        if(c != failed){
            // nextterminal++;
            rt = makeNode1("CT", makeNode0("."));
            rt->leftmostchild->rightsibling = c;
            return rt;
        }else{return failed;}
    }else{  return makeNode1("CT", makeNode0("e"));  }
}

tree S(){
    tree a;
    tree st;
    a = A();
    if(a != failed){
        st = ST();
        if(st != failed){
            tree rt;
            rt = makeNode1("S", a);
            a->rightsibling = st;
            return rt;
        }else{return failed;}
    }else{return failed;}
}

tree ST(){
    if(*nextterminal == '*'){
        tree rt;
        tree st;
        nextterminal++;
        st = ST();
        if(st != failed){
            // nextterminal++;
            rt = makeNode1("ST", makeNode0("*"));
            rt->leftmostchild->rightsibling = st;
            return rt;
        }else{
            return failed;
        }
    }else{
        return makeNode1("ST", makeNode0("e")) ;
    }
}

tree A(){
    tree e;
    if(*nextterminal == '('){
        nextterminal++; // makeNode0('(') in final masterpiece
        e = E();
        if(e != failed && *nextterminal == ')'){
            nextterminal++;
            return makeNode3("A", makeNode0("C"), e, makeNode0(")"));
        }else{
            return failed;
        }
    }else{  e = X();  if(e != failed){return makeNode1("A", e) ;} else{return failed;}   }
}

tree X(){
    tree rt;
    if(*nextterminal >= 97 || *nextterminal <= 122){
        tree leaf = makeNode0(*nextterminal+"");
        rt = makeNode1("X", leaf);
        nextterminal++;
        return rt;
    }else{
        return failed;
    }
}


int main(){
    nextterminal = "a|b.c*";
    tree parsetree = E();
    // printf("%s",parsetree->label);
    traverse(parsetree);
    
}