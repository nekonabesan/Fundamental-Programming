require __dir__ + "/spec_helper"
require __dir__ + '/../fp03_01.rb'

describe "演習1" do
=begin
 a. 0 から 99 までの数のうち、2 の倍数でも 3 の倍数でもないものだけを順に打ち出す。
=end
  context "a" do
    it "a" do
      results = a
      expect(results).to eq [1,5,7,11,13,17,19,23,25,29,31,35,37,41,43,47,49,53,55,59,61,65,67,71,73,77,79,83,85,89,91,95,97]
    end
  end
=begin
 b. 0 から 99 までの数を順に打ち出すが、ただし 3 の倍数の時は fizz、5 の倍数の時は buzz、
 3 の倍数かつ 5 の倍数の時は fizzbuzz と (数値の代わりに) 打ち出す (fizzbuzz 問題)。
=end
  context "b" do
    it "b" do
      results = b
      expect(results).to eq  ["fizzbuzz", 1, 2, "fizz", 4, "buzz", "fizz", 7, 8, "fizz", "buzz",
        11, "fizz", 13, 14, "fizzbuzz", 16, 17, "fizz", 19, "buzz",
        "fizz", 22, 23, "fizz", "buzz", 26, "fizz", 28, 29, "fizzbuzz",
        31, 32, "fizz", 34, "buzz", "fizz", 37, 38, "fizz", "buzz",
        41, "fizz", 43, 44, "fizzbuzz", 46, 47, "fizz", 49, "buzz",
        "fizz", 52, 53, "fizz", "buzz", 56, "fizz", 58, 59, "fizzbuzz",
        61, 62, "fizz", 64, "buzz", "fizz", 67, 68, "fizz", "buzz",
        71, "fizz", 73, 74, "fizzbuzz",76, 77, "fizz", 79, "buzz",
        "fizz", 82, 83, "fizz", "buzz", 86, "fizz", 88, 89, "fizzbuzz",
        91, 92, "fizz", 94, "buzz", "fizz", 97, 98, "fizz"]
    end
  end
=begin
 c. 0 から 99 までの数を順に打ち出すが、ただし 3 の倍数と 3 がつく数字の時は数値の代わり
 に aho と打ち出す。
=end
  context "c" do
    it "c" do
      results = c
      expect(results).to eq ["aho", 1, 2, "aho", 4, 5, "aho", 7, 8, "aho", 10,
        11, "aho", "aho", 14, "aho", 16, 17, "aho", 19, 20,
        "aho", 22, "aho", "aho", 25, 26, "aho", 28, 29, "aho",
        "aho", "aho", "aho", "aho", "aho", "aho", "aho", "aho", "aho", 40,
        41, "aho", "aho", 44, "aho", 46, 47, "aho", 49, 50,
        "aho", 52, "aho", "aho", 55, 56, "aho", 58, 59, "aho",
        61, 62, "aho", 64, 65, "aho", 67, 68, "aho", 70,
        71, "aho", "aho", 74, "aho", 76, 77, "aho", 79, 80,
        "aho", 82, "aho", "aho", 85, 86, "aho", 88, 89, "aho",
        91, 92, "aho", 94, 95, "aho", 97, 98, "aho"]
    end
  end
end
