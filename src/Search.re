
let rec binarySearch_ = (arr, item, low, high) => {
  if (low > high) 
    None
  else {
    let mid = (low + high) / 2;
    let guess = arr[mid];
    if (guess == item)  
      Some(mid)
    else if (guess > item)
      /* Using tail recursion causes generated JS to not use recursion */
      binarySearch_(arr, item, low, mid - 1)
    else 
      binarySearch_(arr, item, mid + 1, high)
  }
};

let binarySearch = (item, arr) => {
  switch (arr) {
  | [||] => None
  | [|x|] => (x == item) ? Some(0) : None
  | _ => binarySearch_(arr, item, 0, Array.length(arr) - 1) 
  };
};
