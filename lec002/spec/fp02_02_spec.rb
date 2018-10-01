require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_02.rb'

describe "演習2" do
  describe "a"do
    it "a(10.100000001,0)" do
      results = a(10.100000001,0)
      expect(results).to eq 10.100000001
    end
    it "a(1,nil)" do
      results = a(1,nil)
      expect(results).to eq 1
    end
    it "a(0,-1)" do
      results = a(0,-1)
      expect(results).to eq 0
    end
  end
  describe "b" do
    it "b(1,-5,8.0)" do
      results = b(1,-5,8.0)
      expect(results).to eq 8.0
    end
    it "b(0,-5,nil)" do
      results = b(0,-5,nil)
      expect(results).to eq 0
    end
    it "b(1,-5,8.0)" do
      results = b(0.01,0.000000125,-2.0)
      expect(results).to eq 0.01
    end
  end
  describe "c" do
    it "c(-0.00000000125)" do
      results = c(-0.00000000125)
      expect(results).to eq "negative"
    end
    it "c(nil)" do
      results = c(nil)
      expect(results).to eq "zero"
    end
    it "c(nil)" do
      results = c(0.0)
      expect(results).to eq "zero"
    end
    it "c(8)" do
      results = c(8)
      expect(results).to eq "positive"
    end
  end
end
