open Jest;
open Belt.Array;

let selectionSort = Sort.selectionSort;
let quickSort = Sort.quickSort;

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

describe("Quick sort", () => {
  open Expect;

  test("0 elements", () => {
    [||]
    |> quickSort |> expect |> toEqual([||])
  });

  test("1 element", () => {
    [|55|]
    |> quickSort |> expect |> toEqual([|55|])
  });

  test("2 elements", () => {
    [|44, 55|]
    |> quickSort |> expect |> toEqual([|44, 55|])
  });

  test("2 elements flipped", () => {
    [|55, 44|]
    |> quickSort |> expect |> toEqual([|44, 55|])
  });

  test("5 elements", () => {
    [|4,3,1,5,2|]
    |> quickSort |> expect |> toEqual(range(1, 5))
  });

  test("7 elements with repeating numbers", () => {
    [|4,1,3,1,5,2,3|]
    |> quickSort |> expect |> toEqual([|1, 1, 2, 3, 3, 4, 5|])
  });

  test("Many elements", () => {
    let result = range(1, 200) |> shuffle |> quickSort;
    result |. Belt.SortArray.isSorted(compare) |> expect |> toBe(true)
  });
});
