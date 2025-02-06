#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int d = b * b - 4 * a * c;

  if (d > 0)
  {
    cout << "Real and Distinct" << endl;
    int root1 = (-b + sqrt(d)) / (2 * a);
    int root2 = (-b - sqrt(d)) / (2 * a);
    cout << min(root1, root2) << " " << max(root1, root2) << endl;
  }
  else if (d == 0)
  {
    cout << "Real and Equal" << endl;
    int root = -b / (2 * a);
    cout << root << " " << root << endl;
  }
  else
  {
    cout << "Imaginary" << endl;
  }

  return 0;
}

char c;
cin >> c;

if (c >= 'a' && c <= 'z')
{
  cout << "lowercase" << endl;
}
else if (c >= 'A' && c <= 'Z')
{
  cout << "UPPERCASE" << endl;
}
else
{
  cout << "Invalid" << endl;
}

return 0;
}

#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  // Upper half of the diamond
  for (int i = n; i >= 1; i--)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    int spaces = 2 * n - 2 * i;
    for (int j = 1; j <= spaces; j++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  // Lower half of the diamond
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    int spaces = 2 * n - 2 * i;
    for (int j = 1; j <= spaces; j++)
    {
      cout << " ";
    }
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }

  return 0;
}
