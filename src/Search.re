
let binarySearch = (item, arr) => {
  let rec find = (arr, low, high) => {
    if (low > high) 
      None
    else {
      let mid = (low + high) / 2;
      let guess = arr[mid];
      if (guess == item)  
        Some(mid)
      else if (guess > item)
        find(arr, low, mid - 1)
      else 
        find(arr, mid + 1, high)
    }
  };

  switch (arr) {
  | [||] => None
  | [|x|] => (x == item) ? Some(0) : None
  | _ => find(arr, 0, Array.length(arr) - 1) 
  };
}