typedef struct {
int a; int b; int c; int d;
char s[100];
} STRUCT;
STRUCT f(STRUCT r) {
STRUCT local;
local = r;
local.a++; local.b++;
local.c++; local.d++;
return local;
}
STRUCT global, result;
int main(int argc, char *argv[]) {
result = f (global);
return 0;
}