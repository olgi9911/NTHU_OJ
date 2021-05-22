#include <stdio.h>
#include <stdlib.h>
typedef struct Card{
    int i;
    struct Card *next;
}Card;

Card *create(int input){
    Card *newCard = (Card*)calloc(1, sizeof(Card));
    newCard -> i = input;
    return newCard;
}

int main(){
    int n, m, num, a, b;
    char operation[5];
    Card *curr, *head, *end, *temp, *beforeA, *beforeAplusB, *tempA, *AplusB;
    curr = head = create(-1);
    scanf("%d %d", &n, &m);
    while(n--){
        scanf("%d", &num);
        curr = curr -> next = create(num);
    }
    end = curr -> next = create(-1);
    
    while(m--){
        curr = head;
        scanf("%s %d %d", operation, &a, &b);
        if(operation[0] == 'A'){ //ADD
            temp = create(b);
            while(a--)
                curr = curr -> next;
            temp -> next = curr -> next;
            curr -> next = temp;
        }
        else if(operation[0] == 'C'){ //CUT
            if(a == 0) continue; //Already at the top of the stack
            for(int i = 0; curr != end; i++){
                if(i == a)
                    beforeA = curr; //card idx_(a-1)
                else if(i == a + b)
                    beforeAplusB = curr; //card idx_(a+b-1)
                
                curr = curr -> next;
            }
            tempA = beforeA -> next; //card idx_a
            AplusB = beforeAplusB -> next; //card idx_(a+b)
            beforeAplusB -> next = head -> next;
            head -> next = tempA;
            beforeA -> next = AplusB;
        }
    }
    curr = head -> next;
    while(curr != end){
        printf("%d\n", curr -> i);
        curr = curr -> next;
    }
}