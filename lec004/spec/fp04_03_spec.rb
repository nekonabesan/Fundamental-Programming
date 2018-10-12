require __dir__ + "/spec_helper"
require __dir__ + '/../fp04_03.rb'

describe "演習3" do
  context "a" do
    it "a_mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])" do
      results = a_mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])
      expect(results).to eq [[4,5,6,7],[12,17,22,27],[20,29,38,47]]
    end
    it "a_mul(nil,[1,2])" do
      results = a_mul(nil,[1,2])
      expect(results).to be_a(ArgumentError)
    end
    it "a_mul([1,2],nil)" do
      results = a_mul([1,2],nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "b" do
    it "b([[1,1,1],[1,1,1]])" do
      results = b([[1,1,1],[1,1,1]])
      expect(results).to eq [[1, 1], [1, 1], [1, 1]]
    end
    it "transpose([[2,3,-1],[5,7,0]])" do
      results = b([[2,3,-1],[5,7,0]])
      expect(results).to eq [[2, 5], [3, 7], [-1, 0]]
    end
    it "transpose(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "c" do
    it "c_mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])" do
      results = c_mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])
      expect(results).to eq [[4,5,6,7],[12,17,22,27],[20,29,38,47]]
    end
    it "c_mul(nil,[1,2])" do
      results = c_mul(nil,[1,2])
      expect(results).to be_a(ArgumentError)
    end
    it "c_mul([1,2],nil)" do
      results = c_mul([1,2],nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
