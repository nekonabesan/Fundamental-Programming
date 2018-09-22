require __dir__ + "/spec_helper"
require __dir__ + '/../fp02_05.rb'

describe "演習5" do
  it "main(4,4)" do
    results = main(4,4)
    expect(results).to eq 4
  end
  it "main(27,81)" do
    results = main(36,81)
    expect(results).to eq 9
  end
  it "main(21,14)" do
    results = main(21,14)
    expect(results).to eq 7
  end
  it "main(nil,9)" do
    results = main(nil,9)
    expect(results).to be_a(ArgumentError)
  end
end
