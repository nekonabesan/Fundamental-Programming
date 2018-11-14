require __dir__ + "/spec_helper"
require __dir__ + '/../fp07_05.rb'


describe "演習5" do
  context "binsort(a)" do
    it "binsort([999,999999,9,99,3,1])" do
      results = binsort([999,999999,9,99,3,1])
      expect(results).to eq [1,3,9,99,999,999999]
    end
    it "binsort([5,4,3,2,1,0])" do
      results = binsort([5,4,3,2,1,0])
      expect(results).to eq [0,1,2,3,4,5]
    end
    it "binsort([[0,99,33,33,99])" do
      results = binsort([0,99,33,33,99])
      expect(results).to eq [0,33,33,99,99]
    end
  end
end
