  //number of existed values strictly lower than l
			int l=lower_bound(coords.begin(),coords.end(),left) -coords.begin();
			//number of existed values lower or equal to r
				//note we can't use lowerbound because it miscalucaltes the answer if there is no copy of the target
			int r=upper_bound(coords.begin(),coords.end(),right)-coords.begin();




/*

to know how many times x appeared between l and r 
we can store in a map of vector : for each element x  store its occurences in the vector mp[x]
then answer to how many times it appeared from l to r is :
int cnt=upper_bound(indices[x].begin(),indices[x].end(),r) - lower_bound(indices[x].begin(),indices[x].end(),l);


*/
