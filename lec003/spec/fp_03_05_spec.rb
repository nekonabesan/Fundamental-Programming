require __dir__ + "/spec_helper"
require __dir__ + '/../fp03_05.rb'

describe "演習5" do
  describe "a" do
    it "a([1,-10,8,3,0])" do
      results = a([1,-10,8,3,0])
      expect(results).to eq 8
    end
    it "a([-1,-10,-8,-55,0])" do
      results = a([-1,-10,-8,-55,0])
      expect(results).to eq 0
    end
    it "a(nil)" do
      results = a(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "b" do
    it "b([-1,0,2,5,9])" do
      results = b([-1,0,2,5,9])
      expect(results).to eq 4
    end
    it "b([1,0,2,1,2,-10])" do
      results = b([1,0,2,1,2,-10])
      expect(results).to eq 2
    end
    it "b(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "c" do
    it "c([-1,0,2,5,9])" do
      results = c([-1,0,2,5,9])
      expect(results).to match_array([4])
    end
    it "c([1,0,2,1,2,-10])" do
      results = c([1,0,2,1,2,-10])
      expect(results).to match_array([2,4])
    end
    it "c(nil)" do
      results = c(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "d" do
    it "d([1,4,5,11])" do
      results = d([1,4,5,11])
      expect(results).to match_array([1,4,5])
    end
    it "d(nil)" do
      results = d(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "e" do
    it "e([4,11,5,1])" do
      results = e([4,11,5,1])
      expect(results).to match_array([1,4,5,11])
    end
    it "e(nil)" do
      results = e(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  describe "avg" do
    it "avg([5,1,-10,4])" do
      results = avg([5,1,-10,4])
      expect(results).to eq 0.0
    end
    it "avg(nil)" do
      results = avg(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
