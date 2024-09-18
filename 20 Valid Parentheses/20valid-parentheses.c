void push(char* a, int* top, char c);
bool isempty(int* top);
char pop(char* a, int* top);
bool match(char c, char d);

bool isValid(char* s) {
    int n=strlen(s);
    if(n%2!=0){
        return false;
    }
    char a[10000];
    int top=-1;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='(' || c=='{' || c=='['){
            push(a,&top,c);
        }
        if(c==')' || c=='}' || c==']'){
            if(isempty(&top)) return false;
            else{
                char d=pop(a,&top);
                if(!match(c,d)){
                    return false;
                }
            }
        }
    }
    if(isempty(&top)){
        return true;
    }
    else{
        return false;
    }
}

void push(char *a,int *top,char c){
    *top+=1;
    a[*top]=c;
}

bool isempty(int *top){
    if(*top==-1) return true;
    else return false;
}

char pop(char *a,int *top){
    char ans=a[*top];
    *top-=1;
    return ans;
}

bool match(char c,char d){
    if(c=='}' && d!='{') return false;
    else if(c==')' && d!='(') return false;
    else if(c==']' && d!='[') return false;
    else return true;
}