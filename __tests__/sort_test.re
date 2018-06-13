open Jest;
open Belt.Array;

let createSortTestSuite = (title, sortFn) => {
  describe(title, () => {
    open Expect;

    test("0 elements", () => {
      [||]
      |> sortFn |> expect |> toEqual([||])
    });

    test("1 element", () => {
      [|55|]
      |> sortFn |> expect |> toEqual([|55|])
    });

    test("2 elements", () => {
      [|44, 55|]
      |> sortFn |> expect |> toEqual([|44, 55|])
    });

    test("2 elements flipped", () => {
      [|55, 44|]
      |> sortFn |> expect |> toEqual([|44, 55|])
    });

    test("5 elements", () => {
      [|4,3,1,5,2|]
      |> sortFn |> expect |> toEqual(range(1, 5))
    });

    test("7 elements with repeating numbers", () => {
      [|4,1,3,1,5,2,3|]
      |> sortFn |> expect |> toEqual([|1, 1, 2, 3, 3, 4, 5|])
    });

    test("Many elements", () => {
      let result = range(1, 500) |> shuffle |> sortFn;
      result |. Belt.SortArray.isSorted(compare) |> expect |> toBe(true)
    });
  });
};

[
  ("Selection sort", Sort.selectionSort),
  ("Naive quick sort", Sort.naiveQuickSort),
  ("Quick sort", Sort.quickSort),
]
|> List.iter(((title, sortFn)) => 
  createSortTestSuite(title, sortFn));
