require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_07.rb'

describe "演習7" do
  it "71" do
    results = main(71)
    expect(results).to match_array([2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71])
  end
  it "nil" do
    results = main(nil)
    expect(results).to be_a(ArgumentError)
  end
end
