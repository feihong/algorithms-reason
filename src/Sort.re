
module ArrayUtil = {
  /* Return a new Array with the element at the given index removed. */
  let remove = (arr, i) => {
    let part1 = arr |. Array.sub(0, i);
    let len = Array.length(arr) - i - 1;
    let part2 = arr |. Array.sub(i + 1, len);
    Array.append(part1, part2)
  };    
};

module Selection = {
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
    | [||] => raise(Not_found)   /* we should never get here */
    | [|x|] => (x, 0)
    | _ => findSmallest_(arr, 1, Array.length(arr), arr[0], 0)
    }
  };

  let rec sort = (arr, acc) => {
    switch (arr) {
    | [||] => acc
    | _ => {
        let (value, index) = findSmallest(arr);
        let newArr = ArrayUtil.remove(arr, index);
        let newAcc = Array.append(acc, [|value|]);
        sort(newArr, newAcc)
      }
    }
  };
}



let selectionSort: array('a) => array('a) = arr => {
  switch (arr) {
  | [||] => [||]
  | [|x|] => [|x|]
  | _ => Selection.sort(arr, [||])
  }
};

let rec naiveQuickSort = arr => {
  switch (arr) {
  | [||] => arr
  | [|_|] => arr
  | [|x, y|] => (x <= y) ? arr : [|y, x|]
  | _ => {
      let keep = Belt.Array.keep;
      /* Selecting random pivot improves average case performance */ 
      let index = Random.int(Array.length(arr));
      let pivot = arr[index];
      Array.concat([
        arr |. keep(v => v < pivot) |> naiveQuickSort,
        arr |. keep(v => v == pivot),
        arr |. keep(v => v > pivot) |> naiveQuickSort,
      ])
    }
  }
};

module QuickSort = {
  let swap = (arr, i, j) => {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  };

  let partition = (arr, low, high) => {
    let pivotIndex = high;
    /* let pivotIndex = arr |> Array.length |> Random.int; */
    let pivotValue = arr[pivotIndex];

    let i = ref(low - 1);   /* index of smaller element */

    for (j in low to (high - 1)) {
      if (arr[j] <= pivotValue) {
        i := i^ + 1;
        swap(arr, i^, j);
      }
    };
    swap(arr, i^ + 1, high);
    i^ + 1
  };

  let rec sort = (arr, low, high) => {
    let low = ref(low);   /* is it bad practice to shadow the argument var? */

    while (low^ < high) {
      let pivotIndex = partition(arr, low^, high);
      sort(arr, low^, pivotIndex - 1);
      low := pivotIndex + 1;
    }
  }
}

let rec quickSort = arr => {
  /* Sort the array in-place */
  QuickSort.sort(arr, 0, Array.length(arr) - 1);
  arr
};