require __dir__ + "/spec_helper"
require __dir__ + '/../fp03_01.rb'

describe "演習1" do
  #describe "fizz1" do
  #  it "fizz1" do
  #    results = fizz1
  #    expect(results).to
  #  end
  #end
  context "a" do
    it "a" do
      results = a
      expect(results).to match_array([1,5,7,11,13,17,19,23,25,29,31,35,37,41,43,47,49,53,55,59,61,65,67,71,73,77,79,83,85,89,91,95,97])
    end
  end
  describe "b" do

  end
end
