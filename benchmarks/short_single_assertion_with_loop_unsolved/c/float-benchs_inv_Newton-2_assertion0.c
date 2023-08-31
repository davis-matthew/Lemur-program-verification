void assert(int cond) { if (!(cond)) { ERROR : { reach_error(); abort(); } } }
void assume(int cond) { if (!cond) { abort(); } }
union double_int {
double d;
int i;
};
double inv(double A) {
double xi, xsi, temp;
signed int cond, exp;
union double_int A_u, xi_u;
A_u.d = A;
exp = (signed int)((A_u.i & 0x7FF00000) >> 20) - 1023;
xi_u.d = 1;
xi_u.i = ((1023 - exp) << 20);
xi = xi_u.d;
cond = 1;
while (cond) {
xsi = 2 * xi - A * xi * xi;
temp = xsi - xi;
cond = ((temp > 1e-10) || (temp < -1e-10));
xi = xsi;
}
return xi;
}
int main() {
double a, r;
a = __VERIFIER_nondet_double();
assume(a >= 20. && a <= 30.);
r = inv(a);
assert(r >= 0 && r <= 0.06);
return 0;
}