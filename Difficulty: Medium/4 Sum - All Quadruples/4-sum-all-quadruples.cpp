class Solution {
	public:
	vector<vector<int>> fourSum(vector<int> &arr, int target) {
		// code here
		int n = arr.size();
		vector<vector<int>> ans;
		sort(arr.begin(),arr.end());
		int i = 0,j = i+1,k = j+1,l = n-1;
		while(i<n){
		    if(i<n && i>0 && arr[i]==arr[i-1]){
		        i++;
		        continue;
		    }
		    j = i+1;
		    while(j<n){
		        if(j<n && j>i+1 && arr[j]==arr[j-1]){
		            j++;
		            continue;
		        }
		        k = j+1,l = n-1;
		        while(k<l){
		            if(arr[i]+arr[j]+arr[k]+arr[l]==target){
		                ans.push_back({arr[i],arr[j],arr[k],arr[l]});
		                k++;
		                while(k<l && arr[k]==arr[k-1]) k++;
		                l--;
		                while(k<l && arr[l]==arr[l+1]) l--;
		            }
		            else if(arr[i]+arr[j]+arr[k]+arr[l]<target){
		                k++;
		            }
		            else{
		                l--;
		            }
		        }
		        j++;
		    }
		    i++;
		}
		return ans;
	}
};
