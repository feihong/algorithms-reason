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
    
});