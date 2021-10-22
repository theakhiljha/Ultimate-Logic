/// <reference types="cypress" />

context('Window', () => {
  beforeEach(() => {
    cy.visit('https://stage-truckbux.workq.in/')
  })

  it('open in Mac 15', () => {
    // https://on.cypress.io/window
    cy.viewport('macbook-15')
    cy.screenshot()   
    cy.wait(200)
  })
  it('open in Mac 13', () => {
    // https://on.cypress.io/window
    cy.viewport('macbook-13')
    cy.screenshot()   
    cy.wait(200)
  })
  it('open in ipad-2', () => {
    // https://on.cypress.io/window
    cy.viewport('ipad-2')
    cy.screenshot()   
    cy.wait(200)
  })
  it('open in iphone-6', () => {
    // https://on.cypress.io/window
    cy.viewport('iphone-6')
    cy.screenshot()   
    cy.wait(200)
  })
 
})
