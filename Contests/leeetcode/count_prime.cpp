class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> primearray(n + 1, true);
        for (int i = 2; i * i <= n; i++)
        {
            for (int j = i * i; j < n; j += i)
            {
                primearray[j] = false;
            }
        }
        // if not prime false it

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (primearray[i])
                count++;
        }
        return count;
    }
};