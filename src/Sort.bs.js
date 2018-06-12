// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function remove(arr, i) {
  var part1 = $$Array.sub(arr, 0, i);
  var high = (arr.length - i | 0) - 1 | 0;
  var part2 = $$Array.sub(arr, i + 1 | 0, high);
  return $$Array.append(part1, part2);
}

var Array2 = /* module */[/* remove */remove];

function findSmallest_(arr, _i, length, _minVal, _minIndex) {
  while(true) {
    var minIndex = _minIndex;
    var minVal = _minVal;
    var i = _i;
    if (i >= length) {
      return /* tuple */[
              minVal,
              minIndex
            ];
    } else {
      var value = Caml_array.caml_array_get(arr, i);
      var match = Caml_obj.caml_lessthan(value, minVal) ? /* tuple */[
          value,
          i
        ] : /* tuple */[
          minVal,
          minIndex
        ];
      _minIndex = match[1];
      _minVal = match[0];
      _i = i + 1 | 0;
      continue ;
    }
  };
}

function findSmallest(arr) {
  var len = arr.length;
  if (len !== 1) {
    if (len !== 0) {
      return findSmallest_(arr, 1, arr.length, Caml_array.caml_array_get(arr, 0), 0);
    } else {
      throw Caml_builtin_exceptions.not_found;
    }
  } else {
    var x = arr[0];
    return /* tuple */[
            x,
            0
          ];
  }
}

function selectionSort_(_arr, _acc) {
  while(true) {
    var acc = _acc;
    var arr = _arr;
    if (arr.length !== 0) {
      var match = findSmallest(arr);
      var newArr = remove(arr, match[1]);
      var newAcc = $$Array.append(acc, /* array */[match[0]]);
      _acc = newAcc;
      _arr = newArr;
      continue ;
    } else {
      return acc;
    }
  };
}

function selectionSort(arr) {
  var len = arr.length;
  if (len !== 1) {
    if (len !== 0) {
      return selectionSort_(arr, /* array */[]);
    } else {
      return /* array */[];
    }
  } else {
    return /* array */[arr[0]];
  }
}

exports.Array2 = Array2;
exports.findSmallest_ = findSmallest_;
exports.findSmallest = findSmallest;
exports.selectionSort_ = selectionSort_;
exports.selectionSort = selectionSort;
/* No side effect */
