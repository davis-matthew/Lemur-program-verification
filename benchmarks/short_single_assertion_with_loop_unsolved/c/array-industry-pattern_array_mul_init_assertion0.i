void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
short __VERIFIER_nondet_short();
int main() {
int a[100000];
int b[100000];
int k;
int i;
for (i = 0; i < 100000; i++) {
a[i] = i;
b[i] = i;
}
for (i = 0; i < 100000; i++) {
if (__VERIFIER_nondet_short()) {
k = __VERIFIER_nondet_short();
a[i] = k;
b[i] = k * k;
}
}
for (i = 0; i < 100000; i++) {
assert(a[i] == b[i] || b[i] == a[i] * a[i]);
}
}