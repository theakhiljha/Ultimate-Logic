function radixSort(arr) {
    function mostDigits(arr) {
        var maxlength = 0;
        for(var i = 0 ;i < arr.length ; i++) {
            maxlength = Math.max(maxlength,digiCount(arr[i]));
        }
        return maxlength;
    }
    function digiCount(num) {
        if(num === 0) {
            return 1;
        }
        return Math.floor(Math.log10(Math.abs(num))) + 1;
    }
    function getDigit(num,placevalue) {
        return Math.floor(Math.abs(num) / Math.pow(10,placevalue) % 10);
 
     }
   


    var largestDigitlength = mostDigits(arr);
    
    for (var k = 0 ; k < largestDigitlength ; k++) {
      let digiBuckets = Array.from({length:10},() => []);
      for( var i = 0 ; i < arr.length ; i++) {
         let digit= getDigit(arr[i],k);
        
         digiBuckets[digit].push(arr[i]);
         
         
      }    
          
      arr = [] .concat(...digiBuckets);
         
      
    }
    
    return arr;
}















console.log(radixSort([24,55,1,100]));
