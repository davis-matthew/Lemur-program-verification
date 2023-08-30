void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
long gcd_test(long a, long b) {
if (a < 0) {
a = -a;
}
if (b < 0) {
b = -b;
}
if (a == 0) {
return b;
}
while (b != 0) {
if (a > b) {
a = a - b;
} else {
b = b - a;
}
}
return a;
}
int main() {
long x;
long y;
long g;
x = 63;
y = 18;
g = gcd_test(x, y);
assert(x % g == 0);
return 0;
}