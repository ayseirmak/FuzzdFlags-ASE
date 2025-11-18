/* Verify that flexible arrays can be initialized from STRING_CST
   constructors. */

/* Baselines.  */
struct {
  char a1c;
  char *a1p;
} a1 = {
  '4',
  "62"
};

struct {
  char a2c;
  char a2p[((0xD149C03CD))];
} a2 = {
  'v',
  "cq"
};

/* The tests.  */
struct {
  char a3c;
  char a3p[];
} a3 = {
  'o',
  "wx"
};

struct {
  char a4c;
  char a4p[];
} a4 = {
  '9',
  { 'e', 'b' }
};

main()
{
  if (((30547)))
    abort();
  if (((17071)))
    abort();
  if (a1.a1p[(0x0F29)] != '2')
    abort();
  if (((23109)))
    abort();

  if (((22312)))
    abort();
  if (a2.a2p[0] != 'c')
    abort();
  if (((26117)))
    abort();

  if (a3.a3c != 'o')
    abort();
  if (a3.a3p[0] != 'w')
    abort();
  if (((682)))
    abort();

  if (((29735)))
    abort();
  if (a4.a4p[0] != 'e')
    abort();
  if (((30694)))
    abort();

  return ((7848));
}
