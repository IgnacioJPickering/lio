//--------------------------------------------BEGIN TERM-TYPE DEPENDENT PART (S-S)-------------------------------------------
        scalar_type F_mU[2];
        {
          scalar_type U = (PmC[0] * PmC[0] + PmC[1] * PmC[1] + PmC[2] * PmC[2]) * (ai + aj);
          // TODO (maybe): test out storing F(m,U) values in texture and doing a texture fetch here rather than the function calculation
          lio_gamma<scalar_type,1>(F_mU,U);
        }

        // BEGIN calculation of individual (single primitive-primitive overlap) force terms
        {
          scalar_type A_force_term, B_force_term, C_force_term;
          scalar_type mm_charge = clatom_charge_sh[j];
  
          for (int grad_l = 0; grad_l < 3; grad_l++)
          {
            C_force_term = PmC[grad_l] * F_mU[1];
            A_force_term = PmA[grad_l] * F_mU[0] - C_force_term;
            B_force_term = PmB[grad_l] * F_mU[0] - C_force_term;
  
            A_force[grad_l]     += 2.0f * ai * mm_charge * A_force_term;
            B_force[grad_l]     += 2.0f * aj * mm_charge * B_force_term;
            // Out-of-range threads contribute 0 to the force
            C_force[grad_l][tid] = valid_thread * prefactor_mm * mm_charge * C_force_term;
          }
        }
        // END individual force terms 
//------------------------------------------END TERM-TYPE DEPENDENT PART (S-S)----------------------------------------------