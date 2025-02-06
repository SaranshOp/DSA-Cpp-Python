/*

	Time Complexity: O(N * log(sumOfPages))
	Space Complexity: O(1)

	where N is the number of books and 'sumOfPages' is the sum of the pages of each book.

*/

// Function to get the sum of the pages of each book
int getSum(vector<int> &pages)
{
    int sum = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        sum += pages[i];
    }
    return sum;
}

// Function to get the maximum pages of a book 
int getMax(vector<int> &pages)
{
    int maxEle = pages[0];
    for (int i = 1; i < pages.size(); i++)
    {
        if(pages[i] > maxEle)
        {
        	maxEle = pages[i];
        }
    }
    return maxEle;
}

// Function to check if is possible to allocate the books
int isPossibe(vector<int> &pages, int ninjas, int maxPages)
{
    int currPages = 0, currNinjas = 1;

    for(int i = 0; i < pages.size(); i++)
    {
    	// If the pages allocated to the current ninja exceeds the maxPages
        if(pages[i] + currPages > maxPages)
        {
        	// Allocate this book to the next ninja
            currNinjas += 1;
            currPages = pages[i];

            // If we can't allocate the books
            if(currNinjas > ninjas)
            {
                return false;
            }
        }
        // Allocate the book to the current ninja
        else
        {
            currPages += pages[i];
        }
    }

    // If it's possible to allocate the books
    return true;
}

int allocateBooks(vector<int> &pages, int n, int b)
{
	// If ninjas are more than the books
	if(n < b)
	{
		return -1;
	}
	
	// Get the low and high to perform binary search
	int low = getMax(pages), high = getSum(pages); 
	int answer = high;

    while(low <= high)
    {
        int mid = low + (high - low)/2;

        /* Check if it is possible to allocate the books to all ninjas such that 
        the maximum pages allocated to a ninja is less than or equal to mid */
        if(isPossibe(pages, b, mid) == true)
        {
        	// Update the answer
            answer = min(answer, mid);

            // Shift towards left to check with less pages
            high = mid - 1;
        }
        // Shift towards right to consider more pages
        else
        {
        	low = mid + 1;
        } 
    }

    // Return the final answer
    return answer;
}
/*
Similar code but with a slightly diff ifpossoble function

#include <bits/stdc++.h> 

bool ifpossible(vector<int>& pages, int n, int b, int mid) {
    int p = 0; // present book
    int pagecount = 0;
    int ninjacount = 0;
    int holdi = 0;

    for (int i = 1; i <= b; i++) {
        ninjacount = i;
        pagecount = 0;
        for (int j = p; j < n && pagecount + pages[j] <= mid; j++) {
            pagecount += pages[j];
            p = j + 1; // Update p to the next book index
        }
        if (p == n)
            break;
        if (pages[p] > mid)
            return false;
        holdi++;
    }

    if (holdi <= b && p == n)
        return true;
    return false;
}

int allocateBooks(vector<int> &pages, int n, int b)
{

	int totalpages = 0;
	for(int j=0 ; j < n ; j++ ){
		totalpages += pages[j];
	}
	int ans;
	int s = 0; 
	int e = totalpages;
	int mid = s + (e - s)/2 ; 
	if( n < b ) return -1;
		while(s<=e){
		if(ifpossible( pages , n , b , mid )){
			ans = mid;
			e = mid - 1;
		}
		else s = mid + 1;

		mid = s + (e - s)/2 ;
	}
	return mid;
}
 */
