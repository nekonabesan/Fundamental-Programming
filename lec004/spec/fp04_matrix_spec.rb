require __dir__ + "/spec_helper"
require __dir__ + '/../app/model/fp04_matrix.rb'

describe "Class Matrix" do
  obj = Matrix.new
  context "mul" do
    it "mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])" do
      results = obj.mul([[0,1],[2,3],[4,5]],[[0,1,2,3],[4,5,6,7]])
      expect(results).to match_array([[4,5,6,7],[12,17,22,27],[20,29,38,47]])
    end
    it "mul([[1,2],[3,4]],[[5,6],[7,8]])" do
      results = obj.mul([[1,2],[3,4]],[[5,6],[7,8]])
      expect(results).to match_array([[19,22],[43,50]])
    end
    it "mul(nil,[1,2])" do
      results = obj.mul(nil,[1,2])
      expect(results).to be_a(ArgumentError)
    end
    it "mul([1,2],nil)" do
      results = obj.mul([1,2],nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "transpose" do
    it "transpose([[1,1,1],[1,1,1]])" do
      results = obj.transpose([[1,1,1],[1,1,1]])
      expect(results).to match_array([[1, 1], [1, 1], [1, 1]])
    end
    it "transpose([[2,3,-1],[5,7,0]])" do
      results = obj.transpose([[2,3,-1],[5,7,0]])
      expect(results).to match_array([[2, 5], [3, 7], [-1, 0]])
    end
    it "transpose(nil)" do
      results = obj.transpose(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
