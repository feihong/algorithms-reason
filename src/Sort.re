
module Array2 = {
  /* Return a new Array with the element at the given index removed. */
  let remove = (arr, i) => {
    let part1 = Array.sub(arr, 0, i);
    let high = Array.length(arr) - i - 1;
    let part2 = Array.sub(arr, i + 1, high);
    Array.append(part1, part2)
  };    
};

let rec findSmallest_ = (arr, i, length, minVal, minIndex) => {
  if (i >= length)
    (minVal, minIndex)
  else {
    let value = arr[i];
    let (newMinVal, newMinIndex) = 
      if (value < minVal) 
        (value, i)
      else
        (minVal, minIndex);
    findSmallest_(arr, i + 1, length, newMinVal, newMinIndex)
  }
};

let findSmallest = arr => {
  switch (arr) {
  | [||] => raise(Not_found)
  | [|x|] => (x, 0)
  | _ => findSmallest_(arr, 1, Array.length(arr), arr[0], 0)
  }
};

let rec selectionSort_ = (arr, acc) => {
  switch (arr) {
  | [||] => acc
  | _ => {
      let (value, index) = findSmallest(arr);
      let newArr = Array2.remove(arr, index);
      let newAcc = Array.append(acc, [|value|]);
      selectionSort_(newArr, newAcc)
    }
  }
};

let selectionSort: array('a) => array('a) = arr => {
  switch (arr) {
  | [||] => [||]
  | [|x|] => [|x|]
  | _ => selectionSort_(arr, [||])
  }
};