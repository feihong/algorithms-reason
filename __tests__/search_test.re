open Jest;

let binarySearch = Search.binarySearch;

describe("Binary search", () => {
  open Expect;

  test("0 elements", () => {
    [||]
    |> binarySearch(3) |> expect |> toBe(None)
  });

  test("1 element, not found", () => {
    [|22|] 
    |> binarySearch(3) |> expect |> toBe(None)
  });

  test("1 element, found", () => {
    [|22|] 
    |> binarySearch(22) |> expect |> toEqual(Some(0))
  });

  test("8 elements, found", () => {
    [|1, 2, 3, 4, 5, 6, 7, 8|]
    |> binarySearch(6) |> expect |> toEqual(Some(5))
  });

  test("8 elements, not found", () => {
    [|1, 2, 3, 4, 5, 6, 7, 8|]
    |> binarySearch(-12) |> expect |> toEqual(None)
  });

  test("9 elements, found", () => {
    [|1, 2, 3, 4, 5, 6, 7, 8, 9|]
    |> binarySearch(2) |> expect |> toEqual(Some(1))
  });

  test("9 elements, not found", () => {
    [|1, 2, 3, 4, 5, 6, 7, 8, 9|]
    |> binarySearch(44) |> expect |> toEqual(None)
  });

  test("1000 elements, found", () => {
    Belt.Array.range(1, 1000)
    |> binarySearch(227) |> expect |> toEqual(Some(226))
  });
});