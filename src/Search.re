
let binarySearch = (item, arr) => {
  let find = (arr, low, high) => {
    None
  };

  switch (arr) {
  | [||] => None
  | [|x|] => (x == item) ? Some(0) : None
  | _ => find(arr, 0, Array.length(arr) - 1) 
  };
}