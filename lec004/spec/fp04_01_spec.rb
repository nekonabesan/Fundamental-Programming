require __dir__ + "/spec_helper"
require __dir__ + '/../fp04_01.rb'

describe "e" do
  it "Include Array 8" do
    results = e(8)
    expect(results).to match_array([8])
  end
  it "Include Array 5" do
    results = e(5)
    expect(results).to match_array([8,5])
  end
  it "Include Array 3" do
    results = e(3)
    expect(results).to match_array([8,5,3])
  end
end
