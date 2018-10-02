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
  end
end
