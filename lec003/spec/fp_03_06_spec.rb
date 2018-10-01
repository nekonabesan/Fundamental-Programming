require __dir__ + "/spec_helper"
require __dir__ + '/../fp03_06.rb'

describe "演習6" do
  context "a_1" do
    it "a_1(100)" do
      results = a_1(100)
      expect(results).to match_array([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "a_1(1)" do
      results = a_1(1)
      expect(results).to be_a(ArgumentError)
    end
    it "a_1(nil)" do
      results = a_1(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "a_2" do
    it "a_2(100)" do
      results = a_2(100)
      expect(results).to match_array([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "a_2(1)" do
      results = a_2(1)
      expect(results).to be_a(ArgumentError)
    end
    it "a_2(nil)" do
      results = a_2(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
  context "b" do
    it "b(100)" do
      results = b(100)
      expect(results).to match_array([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])
    end
    it "b(1)" do
      results = b(1)
      expect(results).to be_a(ArgumentError)
    end
    it "b(nil)" do
      results = b(nil)
      expect(results).to be_a(ArgumentError)
    end
  end
end
