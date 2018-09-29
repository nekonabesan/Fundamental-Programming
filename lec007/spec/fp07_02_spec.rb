require __dir__ + "/spec_helper"
require __dir__ + '/../fp07_02.rb'


describe "演習2" do
=begin
  a. 配列 a の位置 i が空いているものとして、位置 i より前にある x より大きい要素を (位
  置 i を埋めるように)1 つずつ後ろに詰めて行き、最終的な空きの位置を返すメソッド
  shiftlarger(a, i, x) を作りなさい (すべての値が x より大きければ全部詰めて位置
  0 番が空くので 0 を返す)。正しく動作することを確認すること。
=end
  describe "shiftlarger(a, i, x)" do
    it "shiftlarger([3,6,5,2,1],2,5)" do
      results =  shiftlarger([3,6,5,2,1],0,3)
      expect(results).to eq 0
    end
    it "shiftlarger([1,2,3,4,5],4,5)" do
      results =  shiftlarger([3,6,5,2,1],1,6)
      expect(results).to eq 1
    end
    it "shiftlarger([3,5,6,2,1],2,5)" do
      results =  shiftlarger([3,6,5,2,1],2,5)
      expect(results).to eq 1
    end
    it "shiftlarger([3,5,6,2,1],2,5)" do
      results =  shiftlarger([3,5,6,2,1],3,2)
      expect(results).to eq 0
    end
    it "shiftlarger([3,5,6,2,1],2,5)" do
      results =  shiftlarger([2,3,5,6,1],4,1)
      expect(results).to eq 0
    end
    it "shiftlarger(nil,2,5)" do
      results =  shiftlarger(nil,2,5)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "rewritea" do
    it "" do
      results = rewritea([4,6,1,7,3,9,8],0,1,6)
      expect(results).to match_array([6,4,1,7,3,9,8])
    end
  end
  describe "insertionsort(a)" do
    it "insertionsort([6,4,1,7,3,9,8])" do
      results = insertionsort([6,4,1,7,3,9,8])
      expect(results).to match_array([1,3,4,6,7,8,9])
    end
    it "insertionsort([18,13,12,15,20,14])" do
      results = insertionsort([18,13,12,15,20,14])
      expect(results).to match_array([12,13,14,15,18,20])
    end
  end
end
