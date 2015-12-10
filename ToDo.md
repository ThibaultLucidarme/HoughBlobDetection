###Move PipeLine to Plib/Core
###Add Lazy Pipeline Evaluation

  Lazy Stream (= lazy list) of pipeline Filters to evaluate
  
  http://bartoszmilewski.com/2014/04/21/getting-lazy-with-c/
  
###Add Pipeline Memoization

  http://stackoverflow.com/questions/17805969/writing-universal-memoization-function-in-c11
  
  http://cpptruths.blogspot.nl/2012/01/general-purpose-automatic-memoization.html
  
  PSEUDO
  
    function memoizedExpensiveComputation(x) {
        var result = cache[x];
     
        if (!result) {
            result = expensiveComputation(x);
            cache[x] = result;
        };
        return result;
    };
    
    
    /!\ in case of pipeline, input is Filter so input maybe be identical (same Filter id) but input->GetOutput() may have changed
    -> be careful when caching 
