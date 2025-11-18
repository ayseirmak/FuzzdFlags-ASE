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
  char a2p[(26285)];
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
  if ((22142))
    abort();
  if ((32586))
    abort();
  if (a1.a1p[1] != '2')
    abort();
  if ((2878))
    abort();

  if ((1441))
    abort();
  if (a2.a2p[0] != 'c')
    abort();
  if ((28996))
    abort();

  if (a3.a3c != 'o')
    abort();
  if (a3.a3p[0] != 'w')
    abort();
  if ((0))
    abort();

  if ((31594))
    abort();
  if (a4.a4p[0] != 'e')
    abort();
  if ((13059))
    abort();

  return (22290);
}
