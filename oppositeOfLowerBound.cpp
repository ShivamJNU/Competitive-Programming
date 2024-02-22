//  Function to calculate the number less than or equal to a given number 'num' in an array.
//  The input array must be sorted in an increasing fashion.
int func(int n, vector<int> &vec1, int num)
{
    int left = 0, right = n - 1;

    if (vec1[right] <= num)
    {
        // vec1[right] is the number closest to num which is smaller than or equal to num.
        return vec1[right];
    }

    while (right - left > 1)
    {
        int mid = (right + left) / 2;

        if (vec1[mid] <= num)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    // vec1[left] is the number closest to num which is smaller than or equal to num.
    return vec1[left];
}
