// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Search$Algorithms = require("../src/Search.bs.js");

describe("Binary search", (function () {
        Jest.test("0 elements", (function () {
                return Jest.Expect[/* toBe */2](/* None */0, Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(3, /* array */[])));
              }));
        Jest.test("1 element, not found", (function () {
                return Jest.Expect[/* toBe */2](/* None */0, Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(3, /* array */[22])));
              }));
        Jest.test("1 element, found", (function () {
                return Jest.Expect[/* toEqual */12](/* Some */[0], Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(22, /* array */[22])));
              }));
        Jest.test("8 elements, found", (function () {
                return Jest.Expect[/* toEqual */12](/* Some */[5], Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(6, /* array */[
                                    1,
                                    2,
                                    3,
                                    4,
                                    5,
                                    6,
                                    7,
                                    8
                                  ])));
              }));
        Jest.test("8 elements, not found", (function () {
                return Jest.Expect[/* toEqual */12](/* None */0, Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(-12, /* array */[
                                    1,
                                    2,
                                    3,
                                    4,
                                    5,
                                    6,
                                    7,
                                    8
                                  ])));
              }));
        Jest.test("9 elements, found", (function () {
                return Jest.Expect[/* toEqual */12](/* Some */[1], Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(2, /* array */[
                                    1,
                                    2,
                                    3,
                                    4,
                                    5,
                                    6,
                                    7,
                                    8,
                                    9
                                  ])));
              }));
        Jest.test("9 elements, not found", (function () {
                return Jest.Expect[/* toEqual */12](/* None */0, Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(44, /* array */[
                                    1,
                                    2,
                                    3,
                                    4,
                                    5,
                                    6,
                                    7,
                                    8,
                                    9
                                  ])));
              }));
        return Jest.test("1000 elements, found", (function () {
                      return Jest.Expect[/* toEqual */12](/* Some */[226], Jest.Expect[/* expect */0](Search$Algorithms.binarySearch(227, Belt_Array.range(1, 1000))));
                    }));
      }));

var binarySearch = Search$Algorithms.binarySearch;

exports.binarySearch = binarySearch;
/*  Not a pure module */
