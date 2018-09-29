require __dir__ + "/spec_helper"
require __dir__ + '/../fp07_01.rb'


describe "演習1" do
  describe "arraminrange" do
    it "arraminrange([5,-1,2,0,8],0,4)" do
      results = arraminrange([5,-1,2,0,8],0,4)
      expect(results).to eq 1
    end
    it "arraminrange([5,-1,2,0,8],2,4)" do
      results = arraminrange([5,-1,2,0,8],2,4)
      expect(results).to eq 3
    end
    it "arraminrange([5,-1,2,0,8],2,4)" do
      results = arraminrange([5,10,2,0,8,9,-9,0,2],0,4)
      expect(results).to eq 3
    end
    it "arraminrange([5,-1,2,0,8],2,4)" do
      results = arraminrange([5,10,2,0,8,9,-9,0,2],0,8)
      expect(results).to eq 6
    end
    it "arraminrange([5,-1,2,0,8],2,4)" do
      results = arraminrange(nil,0,8)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "swap" do
    it "swap([1,2,3,4,5],1,5)" do
      results = swap([1,2,3,4,5],0,4)
      expect(results).to match_array([5,2,3,4,1])
    end
    it "swap([-1,-2,-3,-4,-5],2,3)" do
      results = swap([-1,-2,-3,-4,-5],2,3)
      expect(results).to match_array([-1,-4,-3,-2,-5])
    end
    it "swap([1,2,3,4,5],1,5)" do
      results = swap([1,2,3,4,5],1,2)
      expect(results).to match_array([1,3,2,4,5])
    end
    it "swap([5,-1,2,0,8],2,4)" do
      results = swap(nil,0,1)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "selectionsort" do
    it "selectionsort([5,4,3,2,1])" do
      results = selectionsort([5,4,3,2,1])
      expect(results).to match_array([1,2,3,4,5])
    end
    it "selectionsort([1000,100,10,10000,1])" do
      results = selectionsort([1000,100,10,10000,1])
      expect(results).to match_array([1,10,100,1000,10000])
    end
    it "selectionsort([11,1,-1,111,-1])" do
      results = selectionsort([11,1,-1,111,-1])
      expect(results).to match_array([-1,-1,1,11,111])
    end
    it "" do
      results = selectionsort(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
