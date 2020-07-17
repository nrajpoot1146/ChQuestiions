
void main(){
    char *c;
    int num, i;
    scanf("%d", &num);
    int l = 2*num+2;
    c = (char *) malloc(2 * num + 3);
    for (i=0; i < 2 * num + 2; i++){
        if (i < 7){
            c[i] = 'o';
        }else if(i < 14){
            c[i] = '*';
        }else{
            c[i] = '-';
        }
    }
    c[2*num+2] = '\0';
    printf("%s", c);

    int e =

    while(true){

    }
}
