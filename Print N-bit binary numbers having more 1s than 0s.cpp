class Solution{
public:
	//Recursive utility function to generate N-bit binary numbers with specified number of ones
	void NBitBinaryUtil(string number, int extraOnes, int remainingPlaces, vector<string> &ans)
	{
		//Base case: If all places have been filled, add the number to the answer vector and return
		if (remainingPlaces == 0) {
			ans.push_back(number);
			return;
		}
		
		//Recursive call to add a '1' to the current number and update the count of extra ones and remaining places
		NBitBinaryUtil(number + "1", extraOnes + 1, remainingPlaces - 1, ans);
		
		//Check if there are any extra ones that can be used to add a '0'
		if (0 < extraOnes) 
			NBitBinaryUtil(number + "0", extraOnes - 1, remainingPlaces - 1, ans); 
	}

	//Function to generate all N-bit binary numbers with specified number of ones
	vector<string> NBitBinary(int n)
	{
		vector<string> ans;

		string s = "";

		//Call the utility function to recursively generate the N-bit binary numbers
		NBitBinaryUtil(s, 0, n, ans);

		return ans;
	}
   
};
