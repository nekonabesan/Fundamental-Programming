require __dir__ + "/spec_helper"
require __dir__ + '/../fp07_06.rb'


describe "演習6" do
  context "radixsort" do
    it "radixsort([11,3,10,1,15,12,3,7,10])" do
      results = radixsort([11,3,10,1,15,12,3,7,10])
      expect(results).to eq [1,3,3,7,10,10,11,12,15]
    end
    it "radixsort([1,5,4,6,2,3])" do
      results = radixsort([1,5,4,6,2,3])
      expect(results).to eq [1,2,3,4,5,6]
    end
    it "radixsort([1,2,3,4,5,6])" do
      results = radixsort([1,2,3,4,5,6])
      expect(results).to eq [1,2,3,4,5,6]
    end
    it "radixsort([9,1,4,2,10,8,22,3,67,2,9,1,11,99,7,111,5,33,41,2])" do
      results = radixsort([9,1,4,2,10,8,22,3,67,2,9,1,11,99,7,111,5,33,41,2])
      expect(results).to eq [1,1,2,2,2,3,4,5,7,8,9,9,10,11,22,33,41,67,99, 111]
    end
    it "radixsort([9,1,4,2,10,8,22,3,67,2,9,1,11,99,7,111,5,33,41,2])" do
      results = radixsort([100,1,10,89,2,9999,8,100000,3,210,2])
      expect(results).to eq [1,2,2,3,8,10,89,100,210,9999,100000]
    end
  end
end
