void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
int N = 1000000;
int main() {
int i, j = 0, a[N];
unsigned int R = 4;
for (i = 0; i < N; i++) {
a[i] = i + 1;
if (i > N / 2) {
a[i] = i % R;
}
}
for (i = 0; i < N; i++) {
if (a[i] == 0) {
j++;
}
assert(j < (N / 8));
}
return 0;
}