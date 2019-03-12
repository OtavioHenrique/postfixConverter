#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lib/stack.h"

char *postfix(char *expression) {
    static char postfixExpression[256];
    int j = 0;

    Stack operatorStack = createStack(256);

    for(int i = 0; expression[i]; i++) {
        if(isdigit(expression[i])) {
            postfixExpression[j++] = expression[i];
        } else if (strchr("+*-/", expression[i])) {
            addItem(expression[i], operatorStack);
        } else if (expression[i] == ')') {
            postfixExpression[j++] = removeItem(operatorStack);
        }
    }

    postfixExpression[j] = '\0';
    destroyStack(&operatorStack);

    return postfixExpression;
}

int main(void) {
    char expression[256];
    printf("Infix? ");
    gets(expression);
    printf("You entered with expression: %s\n", expression);
    printf("You expression on postfix form: %s\n", postfix(expression));
    return 0;
}
