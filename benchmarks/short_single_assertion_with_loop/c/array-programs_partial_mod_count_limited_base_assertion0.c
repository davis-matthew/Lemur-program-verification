void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N = 1000000;
int main() {
int i, j = 0, k = 0, a[N];
unsigned int R = __VERIFIER_nondet_int();
assume(R > 0);
for (i = 0; i < N; i++) {
a[i] = i + 1;
if (i > N / 2 && k < 1) {
a[i] = i % R;
}
if (a[i] == 0) {
k++;
}
}
for (i = 0; i < N; i++) {
if (a[i] == 0) {
j++;
}
assert(j < 2);
}
return 0;
}