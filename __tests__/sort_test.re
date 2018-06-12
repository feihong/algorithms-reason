open Jest;
open Belt.Array;

let selectionSort = Sort.selectionSort;

describe("Selection sort", () => {
  open Expect;

  test("0 elements", () => {
    [||]
    |> selectionSort |> expect |> toEqual([||])
  });

  test("1 element", () => {
    [|55|]
    |> selectionSort |> expect |> toEqual([|55|])
  });

  test("5 elements", () => {
    [|4,3,1,5,2|]
    |> selectionSort |> expect |> toEqual(range(1, 5))
  });

  test("Many elements", () => {
    let result = range(1, 200) |> shuffle |> selectionSort;
    result |. Belt.SortArray.isSorted(compare) |> expect |> toBe(true)
  });

});

