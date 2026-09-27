  //number of existed values strictly lower than l
			int l=lower_bound(coords.begin(),coords.end(),left) -coords.begin();
			//number of existed values lower or equal to r
				//note we can't use lowerbound because it miscalucaltes the answer if there is no copy of the target
			int r=upper_bound(coords.begin(),coords.end(),right)-coords.begin();
