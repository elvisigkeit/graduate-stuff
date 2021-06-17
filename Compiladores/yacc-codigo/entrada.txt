int tab[5][7];
int i, j;
real x;
x = 1.1;
console >> tab[0][3] >> tab[3][2];
for i in [0..4] begin
  console << '[' << " ";
  for j in [0..6]
    console << tab[i][j] + x << " ";
  console << ']' << ' ';
  x = 0;
end;